from flask import Flask

app = Flask(__name__)

@app.route('/')
def hello_world():
	return 'Hello, my dear AIML World !'
 
@app.route('/home/<name>')
def home(name):
	return "hello, "+name;

if __name__ == '__main__':
	app.run()