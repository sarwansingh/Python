from flask import Flask

app = Flask(__name__)

@app.route('/')
def myroot():
	return 'Hello, I am at root / '

@app.route('/home')
@app.route('/myhome')
def myhome():
	return 'I am at Home'

if __name__ == '__main__':
	app.run()