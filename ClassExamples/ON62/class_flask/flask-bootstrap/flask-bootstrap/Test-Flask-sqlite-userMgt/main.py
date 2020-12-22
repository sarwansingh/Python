# ===========
#   Imports
# ===========
from flask import Flask, render_template, request, redirect, url_for, jsonify
import sqlite3 as sql
from flask_cors import CORS, cross_origin

# ===================
#   Flask instance
# ===================
app = Flask(__name__)

# ======================
#   Allow Cross Origin
# ======================
@app.after_request # blueprint can also be app~~
def after_request(response):
    header = response.headers
    header['Access-Control-Allow-Origin'] = '*'
    return response


# ==================================
#  Insert data in database (SIGNUP)
# ==================================
def insertUser(username, email, password, contact):
    con = sql.connect("test.db")
    cur = con.cursor()
    phone = int(contact)
    query = ("""INSERT INTO USERS
             (username,email,password,contact)
             VALUES ('%s','%s','%s',%d)""" %
             (username, email, password, phone))
    cur.execute(query)
    con.commit()
    con.close()


# =====================================
#  Validating data in database (LOGIN)
# =====================================
def validUser(email, password):
    con = sql.connect("test.db")
    cur = con.cursor()
    query = ("""SELECT * FROM USERS
             where email = '%s' and password = '%s'
             """ %
             (email, password))
    cur.execute(query)
    data = cur.fetchall()
    con.close()
    return data


# ===================
#    Flask Routing
# ===================

@app.route('/')
def home():
    return "go at /signin or /signup"

# Login page
@app.route('/signin/', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        rd = validUser(request.form['email'], request.form['password'])
        if rd:
            return "Sucessful Login"
        else:
            return "UnSucessful login"
    else:
        return render_template('index2.html')


# Signup page
@app.route('/signup/', methods=['GET', 'POST'])
def signup():
    if request.method == 'POST':
        username = request.form['username']
        email = request.form['email']
        password = request.form['password']
        contact = request.form['contact']
        insertUser(username, email, password, contact)
        return redirect(url_for('login'))
    else:
        return render_template('index.html')

# api json 
@app.route('/sum', methods=['GET','POST'])
def sum():
    sum = 0
    a = int(request.args.get('a'))
    b = int(request.args.get('b'))
    sum = a+b
    return jsonify(sum)


# Always at end of file !Important!
if __name__ == '__main__':
    app.secret_key = 'SURAJ_SECRET_KEY'
    app.debug = True
    app.run(host='0.0.0.0', port=5000)
