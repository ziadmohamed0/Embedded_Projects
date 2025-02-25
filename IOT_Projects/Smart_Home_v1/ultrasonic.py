import RPi.GPIO as GPIO
import time 
import paho.mqtt.client as mqtt

# initializations of GPIO
GPIO.setmode(GPIO.BCM)
trig = 23
echo = 24

# GPIO setup
GPIO.setup(trig, GPIO.OUT)
GPIO.setup(echo, GPIO.IN)

# Mqtt Broker initializations
MQTT_BROKER = "192.168.100.25"
MQTT_TOPIC = "sensor/ultrasonic"

# Mqtt client initializations 
client = mqtt.Client()
client.connect(MQTT_BROKER, 1883, 60)

def get_distance():
    GPIO.output(trig, True)
    time.sleep(0.00001)
    GPIO.output(trig, False)

    start_time = time.time()
    stop_time = time.time()

    while GPIO.input(echo) == 0:
        start_time = time.time()

    while GPIO.input(echo) == 1:
        stop_time = time.time()

    time_elapsed = stop_time - start_time
    distance = (time_elapsed * 34300) / 2
    return distance

try:
    while True:
        distance = get_distance()
        print(f"Distance : {distance:.2f} cm")
        client.publish(MQTT_TOPIC, distance)
        time.sleep(1)

except:
    GPIO.cleanup()
