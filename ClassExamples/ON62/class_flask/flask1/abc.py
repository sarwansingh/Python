from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
	return 'Thank you,Machine learning champs to NIELIT !'

@app.route('/ptu/<name>')
def ppp(name):
	return 'we all welcome PTU student - ' + name 

@app.route('/home/<int:age>')
def home(age):
	return "Age = %d" % age


if __name__ == '__main__':
	app.run()