import sqlite3

conn = sqlite3.connect('employee.db')
print "Opened database successfully";

conn.execute('CREATE TABLE students (name TEXT, addr TEXT, city TEXT, pin TEXT)')
print "Table created successfully";
conn.close()
'''
CREATE TABLE "students" (
	"name"	TEXT,
	"email"	TEXT,
	"address"	TEXT,
	"ID"	INTEGER NOT NULL UNIQUE,
	PRIMARY KEY("ID" AUTOINCREMENT)
);
'''