const fs = require('fs');

function day06(groupSize) {
  return new Promise((resolve, reject) => {
    fs.readFile('./input', 'utf8', (err, data) => {
      if (err) {
        reject(err);
        return;
      }
      let i = -1
      let j = 0
      let aux = 0
      let star = 0

      let starArray = []
      let arrAux = ""

      while(++i < data.length) {
        aux = i
        arrAux = ""
        while(j++ < groupSize)
          arrAux += data[i++]

        j = 0
        starArray.push(arrAux)
        i = aux
      }
      i = -1
      while(++i < starArray.length) {
        if (!containsDuplicates(starArray[i]) ){
          star = i + groupSize
          break
        }
      }
      resolve(star);
    });
  });
}

function containsDuplicates(array) {
  return array.length !== new Set(array).size;
}

async function main() {
  let star = await day06(4)
  let star2 = await day06(14)
  console.log(`First ⭐️: ${star}`);
  console.log(`Second ⭐️: ${star2}`);
}
main().then(() => { }).catch(console.log)
