var addon = require('bindings')('my_addon')

var interval = setInterval(function () {
  process.stdout.write('.')
}, 50)

addon.delay(function () {
  clearInterval(interval)
  console.log('Done!')
})

process.stdout.write('Waiting')

