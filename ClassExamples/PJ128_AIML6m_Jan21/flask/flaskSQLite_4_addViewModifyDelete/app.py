from flask import *
import sqlite3

app = Flask(__name__)

@app.route("/")
def index():
	return render_template("index.html");

@app.route("/add")
def add():
	return render_template("add.html")

@app.route("/update")
def update():
	con = sqlite3.connect("employee.db")
	con.row_factory = sqlite3.Row
	cur = con.cursor()
	cur.execute("select id, name  from students ")
	rows = cur.fetchall()
	return render_template("update.html",rows = rows)

@app.route("/modifyrecord",methods = ["POST"])
def update1():
	id = request.form["id"]
	con = sqlite3.connect("employee.db")
	con.row_factory = sqlite3.Row
	cur = con.cursor()
	cur.execute("select *  from students where id=?",(id,)  )
	rows = cur.fetchall()
	return render_template("update1.html",rows = rows)

@app.route("/updaterecord",methods = ["POST","GET"])
def updateRecord():
	msg = "msg"

	if request.method == "POST":
		try:			
			id    = request.form["id"]
			name    = request.form["name"]
			email   = request.form["email"]
			address = request.form["address"]
			with sqlite3.connect("employee.db") as con:
				cur = con.cursor()
				#check the validity of data being send by user.
				cur.execute("update students set name=?, email=?, address=? where id=?",(name,email,address,id))
			
				con.commit()
				msg = " Student updated successfully  "
		except:
			con.rollback()
			msg = " can not update the student record"
		finally:
			return render_template("index.html",msg = msg)
			con.close()

	
@app.route("/savedetails",methods = ["POST","GET"])
def saveDetails():
	msg = "msg"
	if request.method == "POST":
		try:
			name    = request.form["name"]
			email   = request.form["email"]
			address = request.form["address"]
			with sqlite3.connect("employee.db") as con:
				cur = con.cursor()
				#check the validity of data being send by user.
				cur.execute("INSERT into students (name, email, address) values (?,?,?)",(name,email,address))
			
				con.commit()
				msg = " Student successfully Added "
		except:
			con.rollback()
			msg = " can not add the student to the list"
		finally:
			return render_template("index.html",msg = msg)
			con.close()

@app.route("/view")
def view():
	con = sqlite3.connect("employee.db")
	con.row_factory = sqlite3.Row
	cur = con.cursor()
	cur.execute("select * from students ")
	rows = cur.fetchall()
	return render_template("view.html",rows = rows)			

@app.route("/delete")
def delete():
	con = sqlite3.connect("employee.db")
	con.row_factory = sqlite3.Row
	cur = con.cursor()
	cur.execute("select id,name from students ")
	rows = cur.fetchall()
	return render_template("delete.html",rows = rows)	

@app.route("/deleterecord",methods = ["POST"])
def deleterecord():
	id = request.form["id"]
	with sqlite3.connect("employee.db") as con:
		try:
			cur = con.cursor()
			cur.execute("delete from students where id = ?",(id,))
			msg = "record successfully deleted"
		except:
			msg = "can't be deleted"
		finally:
			return render_template("index.html",msg = msg)
	
	
if  __name__ == "__main__":
	app.run()