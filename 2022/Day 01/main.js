const fs = require('fs');

fs.readFile('./input', 'utf8', (err, data) => {
	// Error handling
	if (err) {
    console.error(err);
    return;
  }
  // Split the input into an array of numbers
  data = data.split('\n').map(Number);

  // Variable declaration
  let sum = 0;
  let i = -1;
  let top = [0, 0, 0];
  let update = []

  // Loop through the array and assign top three biggest values
  while(++i < data.length) {
	sum = 0;
	while(data[i] != 0)
		sum += data[i++];
	update = updateTopThree(top[0], top[1], top[2], sum);
	top[0] = update[0];
	top[1] = update[1];
	top[2] = update[2];
  }
	console.log(`First ⭐️: ${top[0]}`);
	console.log(`Second ⭐️: ${top[0] + top[1] + top[2]}`);
});

function updateTopThree(first, second, third, sum){
	if (first < sum){
		third = second;
		second = first;
		first = sum;
	} else if (second < sum){
		third = second;
		second = sum;
	} else if (third < sum)
		third = sum;
	return [first, second, third];
}


