from flask import *

app = Flask(__name__)

@app.route('/')
def hello_world():
	return render_template('first.html')
 
@app.route('/wel')
def home():
	return render_template('welcome.html')

if __name__ == '__main__':
	app.run()