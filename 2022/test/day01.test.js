// importamos la función suma que hemos definido en el archivo suma.js
const suma = require('../Day 01/day01.js');

// usamos el assert de Chai para comprobar si la función suma está implementada correctamente
const assert = require('chai').assert;

describe('Day 01 - Tests', function() {
  it('debería devolver 3 cuando se le pasan 1 y 2', function() {
    const result = suma(1, 2);
    assert.equal(result, 3);
  });

  it('debería devolver -1 cuando se le pasan -1 y 0', function() {
    const result = suma(-1, 0);
    assert.equal(result, -1);
  });
});