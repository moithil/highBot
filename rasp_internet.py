#sudo apt-get install python-bottle

from bottle import route, run
import RPi.GPIO as GPIO

host = '192.168.43.150'
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
led_pins = [18, 19, 20, 21]
led_states = [0, 0, 0, 0]
led_lable = ['FWD', 'REV', 'Left', 'Rigth']
switch_pin = 17

GPIO.setup(led_pins[0], GPIO.OUT)
GPIO.setup(led_pins[1], GPIO.OUT)
GPIO.setup(led_pins[2], GPIO.OUT)
GPIO.setup(led_pins[3], GPIO.OUT)
GPIO.setup(switch_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def switch_status():
	state = GPIO.input(switch_pin)
	if state:
		return 'Up'
	else:
		return 'Down'
		
def html_for_led(led):
	l = str(led)
	result = " <input type='button' onClick='changed(" + l + ")' value='" + led_lable[led] + "'/>"
	return result
	
def update_leds():
	for i, value in enumerate(led_states):
		GPIO.output(led_pins[i], value)

@route('/')
@route('/<led>')
def index(led="n"):
	if led != "n":
		led_num = int(led)
		led_states[led_num] = not led_states[led_num]
		update_leds()
	response = "<script>"
	response += "function changed(led)"
	response += "{"
	response += " window.location.href='/' + led"
	response += "}"
	response += "</script>"
	response += "<title> Pi webcontrol </title>"
	
	#response += '<h1>Project 111</h1>'
	response += '<h2>Button=' + switch_status() + '</h2>'
	#response += '<h2>Display</h2>'
	
	response += '<h2><img src="http://' + host + ':8081/" width="320" height="240"/></h2>'
	response += '<h2>'
	response += html_for_led(0)
	response += html_for_led(1)
	response += html_for_led(2)
	response += html_for_led(3)
	response += '</h2>'

	return response
	
run(host=host, port=8082)
