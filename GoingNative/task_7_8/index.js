/* Simpler timer - you call a delay(x, callback) 
 * method rom JavaScript, your C++ code will sleep 
 * for x milliseconds and then call the callback 
 * function
 */
var bindings = require('bindings');
var addon = bindings('myaddon.node');
console.log("START...");
addon.delay(1000, function(){
	console.log("DONE!!!");
})

