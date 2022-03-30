from flask import Flask,request

app = Flask(__name__)

ind_left = 0
ind_right = 0


# 0 - left
# 1 - right
@app.route("/device_set")
def device_on():
	global ind_left
	global ind_right

	indic = int(request.args.get('indic'))
	swtch = int(request.args.get('swtch'))

	if indic == 0:
		ind_left = swtch

	elif indic == 1:
		ind_right = swtch

	print('ind left',ind_left)
	print('ind right',ind_right)
	
	return '{"status":"ok"}'


@app.route("/device_status")
def device_status():
	global ind_left
	global ind_right
	
	return str(ind_left) + ":" +str(ind_right)

	