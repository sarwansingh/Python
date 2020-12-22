from flask import *
import sqlite3 as sql
app = Flask(__name__)

@app.route('/')
def abc():
	return  render_template('index.html')
	
@app.route('/teacher')
def teacher():
	return  render_template('teacher.html')	

@app.route('/contact')
def contact():
	return  render_template('contact.html')

@app.route('/student')
def studentl():
	#create connection with database
	con = sql.connect("studentsDB.db")
	con.row_factory = sql.Row

   	#create cursor to fetch the records and keep in temp. location

	cur = con.cursor()
	cur.execute("select * from studtable")
	rows = cur.fetchall();
	 
	return render_template("student.html" , record = rows)
	
if __name__ == '__main__':
	app.run(debug = True)