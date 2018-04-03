
var addon = require('bindings')('calculator');

var calculator = new addon.Calculator(0);
console.log(calculator.add(1, 2));

