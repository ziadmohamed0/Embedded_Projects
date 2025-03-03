#!/bin/bash

MQTT_SERVER="192.168.100.25"
MQTT_PORT="1883"

TOPIC_FAN1="motor1/control"
TOPIC_FAN2="motor2/control"

send_mqtt_command() {
    local TOPIC=$1
    local MESSAGE=$2
    mosquitto_pub -h $MQTT_SERVER -p $MQTT_PORT -t $TOPIC -m $MESSAGE
}

while true; do
    echo "Select fan (1 for Fan 1, 2 for Fan 2, 3 for Both Fans, or 'q' to quit):"
    read -r FAN

    if [[ "$FAN" == "q" ]]; then
        echo "Stopping the program..."
        break
    elif [[ "$FAN" == "1" || "$FAN" == "2" || "$FAN" == "3" ]]; then
        echo "Enter command (1 to turn on, 0 to turn off):"
        read -r INPUT

        if [[ "$INPUT" == "1" || "$INPUT" == "0" ]]; then
            if [[ "$FAN" == "1" ]]; then
                echo "Sending command to Fan 1: $INPUT"
                send_mqtt_command $TOPIC_FAN1 $INPUT
            elif [[ "$FAN" == "2" ]]; then
                echo "Sending command to Fan 2: $INPUT"
                send_mqtt_command $TOPIC_FAN2 $INPUT
            elif [[ "$FAN" == "3" ]]; then
                echo "Sending command to Fan 1: $INPUT"
                send_mqtt_command $TOPIC_FAN1 $INPUT
                echo "Sending command to Fan 2: $INPUT"
                send_mqtt_command $TOPIC_FAN2 $INPUT
            fi
        else
            echo "Invalid input! Please enter 1 or 0."
        fi
    else
        echo "Invalid fan selection! Please enter 1, 2, 3, or q to quit."
    fi
done
