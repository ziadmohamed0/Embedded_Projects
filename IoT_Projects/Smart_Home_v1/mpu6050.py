import smbus2
import time 
import paho.mqtt.client as mqtt

# initializations of i2c for mpu6050
MPU6050_ADD = 0x68
bus = smbus2.SMBus(1)

# initializations MPU6050
bus.write_byte_data(MPU6050_ADD, 0x6B, 0)

# Mqtt initializations
MQTT_BROKER = "192.168.100.25"
MQTT_TOPIC = "sensor/mpu6050"

client = mqtt.Client()
client.connect(MQTT_BROKER, 1883, 60)

def read_raw_data(addr):
    high = bus.read_byte_data(MPU6050_ADD, addr)
    low =  bus.read_byte_data(MPU6050_ADD, addr + 1)
    value = (high << 8) | low
    if value > 32768:
        value -= 65536
    return value

def get_mpu_data():
    accel_x = read_raw_data(0x3B) / 16384.0
    accel_y = read_raw_data(0x3D) / 16384.0
    accel_z = read_raw_data(0x3F) / 16384.0

    gyro_x = read_raw_data(0x43) / 131.0
    gyro_y = read_raw_data(0x45) / 131.0
    gyro_z = read_raw_data(0x47) / 131.0

    data = {
            "a_x": round(accel_x, 1),
            "a_y": round(accel_y, 1),
            "accel_z": round(accel_z, 1),

            "g_x": round(gyro_x, 1),
            "g_y": round(gyro_y, 1),
            "g_z": round(gyro_z, 1),
            }  
    return data

try:
    while True:
        mpu_data = get_mpu_data()
        print(mpu_data)
        client.publish(MQTT_TOPIC, str(mpu_data))
        time.sleep(1)

except KeyboardInterrupt:
    bus.close()
    print("MPU6050 Disconnected")

