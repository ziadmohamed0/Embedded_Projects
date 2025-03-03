import paho.mqtt.client as mqtt

mqtt_broker = "localhost"
mqtt_port = 1883
mqtt_topic_esp32 = "esp32/sensor"
mqtt_topic_esp8266 = "esp8266/sensor"

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe(mqtt_topic_esp32)
    client.subscribe(mqtt_topic_esp8266)

def on_message(client, userdata, msg):
    payload = msg.payload.decode()
    if msg.topic == mqtt_topic_esp32:
        print(f"ESP32 Sensor Data: {payload}")
    elif msg.topic == mqtt_topic_esp8266:
        print(f"ESP8266 Sensor Data: {payload}")

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(mqtt_broker, mqtt_port, 60)

client.loop_forever()
