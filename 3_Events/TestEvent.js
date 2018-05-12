var util = require("util");
var EventEmitter = require("events");

function User(){
}
util.inherits(User, EventEmitter);

var eventName = "greet";
User.prototype.sayHi = function(data){
    this.emit(eventName, data);
}
var user = new User();
// добавляем к объекту user обработку события "greet"
user.on(eventName, function(data){
    console.log(data);
});

user.sayHi("I need your clothes...");
