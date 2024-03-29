const fs = require('fs');

fs.readFile('./input', 'utf8', (err, data) => {
	// Error handling
	if (err) {
    console.error(err);
    return;
  }
  // Split the input into an array of numbers
  data = data.split('\n').map(String);

  // Variable declaration
  let i = -1;
  let star1 = 0
  let star2 = 0
  
  // Loop through the array and assign top three biggest values
  	while(++i < data.length) {
		let line = data[i].split(',').map(String);
		let assignments1 = line[0].split('-').map(Number);
		let assignments2 = line[1].split('-').map(Number);
		let min1 = assignments1[0]
		let max1 = assignments1[1]
		let min2 = assignments2[0]
		let max2 = assignments2[1]

		if ((min1 >= min2 && min1 <= max2) && (max1 >= min2 && max1 <= max2))
			star1 += 1
		else if((min2 >= min1 && min2 <= max1) && (max2 >= min1 && max2 <= max1))
			star1 += 1

		if ((min1 >= min2 && min1 <= max2) || (max1 >= min2 && max1 <= max2))
			star2 += 1
		else if((min2 >= min1 && min2 <= max1) || (max2 >= min1 && max2 <= max1))
			star2 += 1
	}
	console.log(`First ⭐️: ${star1}`); //498
  	console.log(`Second ⭐️: ${star2}`);
});
