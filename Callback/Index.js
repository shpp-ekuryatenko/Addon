const s = require('./build/Release/Callback');
var callMe = function(param) {
    console.log(param + " Got the call");
};

s.callThis(callMe);

// Create an object "bicycle"
function bicycle(){
}
// Create an instance of bicycle called roadbike
var roadbike = new bicycle();
// Define a custom property, wheels, on roadbike
roadbike.wheels = 2;
var mobike = new bicycle();
console.log(roadbike);//bicycle { wheels: 2 }
console.log(mobike);//bicycle { }

// Assign the wheels property to the object's prototype
bicycle.prototype.wheels = 4;
var mobibike = new bicycle();
console.log(mobibike.wheels); // 4
console.log(mobike.wheels); // 4
