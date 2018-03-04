const s = require('./build/Release/Scott');
s.init();
console.log( s.MyNum() );
console.log( s.unpack(36) );
console.log( s.handleObj({x:3}) );
s.init();
console.log( s.doubleArray([1,2,3,4]) );

var a2 = [1,2,3,4];
s.on2Array(a2);
console.log( a2 );
console.log( s.on2Array(a2) );
console.log( s.getCnt());

