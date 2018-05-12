/* PUT THE CURRENT THREAD TO SLEEP so nothing else executes
 * delay the callback for the correct amount of time
 */
var addon = require('bindings')('myaddon')

var interval = setInterval(function () {
  process.stdout.write('.')
}, 50)

addon.delay(2000, function () {
  clearInterval(interval)
  console.log('Done!')
})

process.stdout.write('Waiting')

