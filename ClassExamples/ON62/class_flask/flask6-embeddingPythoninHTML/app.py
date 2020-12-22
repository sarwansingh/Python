from flask import *
app = Flask(__name__)

@app.route('/table/<int:num>')
def table(num):
	return render_template('print-table.html',n=num)

if __name__ == '__main__':
	app.run(debug = True)