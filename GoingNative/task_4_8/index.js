/* Takes a String command-line argument, passes it to 
  a native Node.js add-on which prints it to standard 
  output with printf()
*/
var bindings = require('bindings');
var addon = bindings('myaddon.node');
console.log(process.argv[2]);
