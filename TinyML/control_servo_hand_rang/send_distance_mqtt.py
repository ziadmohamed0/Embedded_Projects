"""
    @file: send_distance_mqtt.py
    @author: Ziad Mohammed Fathy
    @brief: Python script to send hand gesture distance data to ESP8266 via MQTT with servo range scaling.
    @version: 0.3
    @date: 2025-03-03
"""

import cv2
import math
import numpy as np
import mediapipe as mp
import paho.mqtt.client as mqtt

# MQTT Configurations
MQTT_BROKER = "192.168.100.25"
MQTT_PORT = 1883
MQTT_TOPIC = "hand_gesture/distance"

# Define the width and height of the video capture
w, h = 620, 480

# Initialize video capture
cap = cv2.VideoCapture(0)
cap.set(3, w)
cap.set(4, h)

# Initialize MediaPipe hand detector
mp_hands = mp.solutions.hands
hands = mp_hands.Hands(min_detection_confidence=0.5)
mp_drawing = mp.solutions.drawing_utils

# Initialize MQTT Client
client = mqtt.Client()
client.connect(MQTT_BROKER, MQTT_PORT, 60)

# Custom Range Mapping Function
def map_range(value, in_min, in_max, out_min, out_max):
    """
    Maps a value from one range to another.
    
    @param value: The input value to be mapped.
    @param in_min: The minimum value of the input range.
    @param in_max: The maximum value of the input range.
    @param out_min: The minimum value of the output range.
    @param out_max: The maximum value of the output range.
    @return: The mapped value.
    """
    return np.clip((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min, out_min, out_max)

def send_distance(distances):
    """
    Publishes the mapped distances (0 to 180) to the MQTT broker.
    
    @param distances: A list of original calculated distances.
    """
    scaled_distances = [int(map_range(d, 20, 150, 0, 180)) for d in distances]
    message = ",".join(map(str, scaled_distances))
    client.publish(MQTT_TOPIC, message)

# Main loop
while True:
    try:
        # Capture frame-by-frame
        ret, img = cap.read()
        if not ret:
            print("Failed to capture image")
            break
        
        # Convert the image to RGB
        img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        results = hands.process(img_rgb)

        if results.multi_hand_landmarks:
            for landmarks in results.multi_hand_landmarks:
                mp_drawing.draw_landmarks(img, landmarks, mp_hands.HAND_CONNECTIONS)

                # Finger points for distance calculations
                points = [
                    mp_hands.HandLandmark.THUMB_TIP,  
                    mp_hands.HandLandmark.INDEX_FINGER_TIP,  
                    mp_hands.HandLandmark.MIDDLE_FINGER_TIP,  
                    mp_hands.HandLandmark.RING_FINGER_TIP,  
                    mp_hands.HandLandmark.PINKY_TIP
                ]

                distances = []
                for i in range(len(points) - 1):  
                    x1, y1 = int(landmarks.landmark[points[i]].x * w), int(landmarks.landmark[points[i]].y * h)
                    x2, y2 = int(landmarks.landmark[points[i + 1]].x * w), int(landmarks.landmark[points[i + 1]].y * h)
                    
                    # Calculate distance between points
                    length = math.hypot(x2 - x1, y2 - y1)
                    distances.append(length)

                # Send mapped values
                send_distance(distances)

        # Display the resulting frame
        cv2.putText(img, "Hand Gesture Distance Sending", (int(w / 2) - 160, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 1, cv2.LINE_AA)
        cv2.imshow("Hand Gesture Distance", img)

        # Break loop on 'q' key
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    except Exception as e:
        print(f"An error occurred: {e}")

# Release resources
cap.release()
cv2.destroyAllWindows()
client.disconnect()
