/* Read a String argument and returns a 
   integer indicating the length of that 
   string
*/
var bindings = require('bindings');
var addon = bindings('myaddon.node');
console.log(addon.length(process.argv[2]));

