from flask import *
app = Flask(__name__)

@app.route('/user/<uname>')
def message(uname):
	return render_template('show.html',name=uname)

if __name__ == '__main__':
	app.run(debug = True)