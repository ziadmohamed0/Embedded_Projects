# imports library
import RPi.GPIO as GPIO
import paho.mqtt.client as mqtt
import time 


# Pins number
## IR sensors pins
IR_SENSOR_1 = 2
IR_SENSOR_2 = 3
IR_SENSOR_3 = 4

## l298 h-bridge driver pins
IN_1 = 26
IN_2 = 19
IN_3 = 13
IN_4 = 6

## Topics
## IR sesnors topics
IR_1_TOPIC = "sensor/ir1"
IR_2_TOPIC = "sensor/ir2"
IR_3_TOPIC = "sensor/ir3"

## l298 h-bridge driver topics
MOTOR_1_TOPIC = "motor/fan1"
MOTOR_2_TOPIC = "motor/fan2"

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

# initializations pins
## IR sensors initializations 
GPIO.setup(IR_SENSOR_1, GPIO.IN)
GPIO.setup(IR_SENSOR_2, GPIO.IN)
GPIO.setup(IR_SENSOR_3, GPIO.IN)

## l298 h-bridge driver initializations
GPIO.setup(IN_1, GPIO.OUT)
GPIO.setup(IN_2, GPIO.OUT)
GPIO.setup(IN_3, GPIO.OUT)
GPIO.setup(IN_4, GPIO.OUT)
GPIO.setup(IN_1, GPIO.OUT)

# initializations mqtt server 
client = mqtt.Client()
RPI_TOPIC = "raspberry/pi"
MQTT_SERVER = "192.168.100.25"
MQTT_PORT = 1883

## function motor 1 (fan) ON.
def motor_1_on():
    GPIO.output(IN_1, GPIO.HIGH)
    GPIO.output(IN_2, GPIO.LOW)

## function motor 1 (fan) OFF.
def motor_1_off():
    GPIO.output(IN_1, GPIO.LOW)
    GPIO.output(IN_2, GPIO.LOW)

## function motor 2 (fan) ON.
def motor_2_on():
    GPIO.output(IN_3, GPIO.HIGH)
    GPIO.output(IN_4, GPIO.LOW)

## function motor 2 (fan) OFF.
def motor_2_off():
    GPIO.output(IN_3, GPIO.LOW)
    GPIO.output(IN_4, GPIO.LOW)

## function send data of sensor to broker
def send_sensor_data(sensor_num, value):
    topic_sens = ""
    if sensor_num == 1:
        topic_sens = IR_1_TOPIC
    elif sensor_num == 2:
        topic_sens = IR_2_TOPIC
    elif sensor_num == 3:
        topic_sens = IR_3_TOPIC
    client.publish(topic_sens, value)

## function monitoring data in broker
def monitor_sensor():
    while True:
        IR_1_VAL = GPIO.input(IR_SENSOR_1)
        IR_2_VAL = GPIO.input(IR_SENSOR_2)
        IR_3_VAL = GPIO.input(IR_SENSOR_3)
        send_sensor_data(1, IR_1_VAL)
        send_sensor_data(2, IR_2_VAL)
        send_sensor_data(3, IR_3_VAL)
        time.sleep(0.00001)

def on_message(client, userdata, message):
    payload = message.payload.decode()
    print(f"Received message: {payload}")
    payload_int = int(payload)
    if message.topic == MOTOR_1_TOPIC:
        if payload_int == 1:
            motor_1_on()
        elif payload_int == 0:
            motor_1_off()
    elif message.topic == MOTOR_2_TOPIC:
        if payload_int == 1:
            motor_2_on()
        elif payload_int == 0:
            motor_2_off()

client.on_message = on_message
client.connect(MQTT_SERVER, MQTT_PORT, 60)
client.subscribe(RPI_TOPIC)
client.subscribe(MOTOR_1_TOPIC)
client.subscribe(MOTOR_2_TOPIC)

client.loop_start()
monitor_sensor()

