const fs = require('fs')

let file = fs.readFileSync("./users.json", "utf-8")
file = JSON.parse(file);

let names = Object.keys(file);
names = JSON.stringify(names)
fs.writeFileSync("./namesDataBase.txt", names, "utf-8")

let pswd = Object.values(file)
for(i = 0; i < pswd.length; i++){
    pswd[i] = pswd[i].pasword
}
pswd = JSON.stringify(pswd)
fs.writeFileSync("./pswdDataBase.txt", pswd, "utf-8")

let user = Object.values(file)
for(i = 0; i < user.length; i++){
    user[i] = user[i].user
}
user = JSON.stringify(user)
fs.writeFileSync("./usersDataBase.txt", user, "utf-8")