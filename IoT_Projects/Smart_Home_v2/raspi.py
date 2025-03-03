import RPi.GPIO as GPIO
import paho.mqtt.client as mqtt
import time

IR_SENSORS = [2, 3, 4]

broker_address = "192.168.100.25"
broker_port = 1883
ir_topic = "ir/sensors"
password_topic = "password/topic"

GPIO.setmode(GPIO.BCM)
for pin in IR_SENSORS:
    GPIO.setup(pin, GPIO.IN)

client = mqtt.Client("RaspberryPi")
client.connect(broker_address, broker_port)

def read_ir_sensors():
    readings = []
    for pin in IR_SENSORS:
        readings.append(GPIO.input(pin))
    return readings

def send_password():
    password = input("Enter the password: ")
    client.publish(password_topic, password)
    print(f"Sent password: {password}")

send_password()

try:
    while True:
        sensor_readings = read_ir_sensors()
        client.publish(ir_topic, str(sensor_readings))

        time.sleep(1)

except KeyboardInterrupt:
    GPIO.cleanup()
    client.disconnect()
