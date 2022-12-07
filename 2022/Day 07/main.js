const fs = require('fs');

const data = fs.readFileSync('input', 'utf8').split('\n').map(String);

let folder_sizes = {}
let dir = ['/']
let i = -1

while (++i < data.length ) {
    let line = data[i].split(" ")
	if(line[0] === "$" && line[1] === "cd" && line[2] == "..") // cd ..
		dir.pop()
	else if (line[0] === "$" && line[1] === "cd" && line[2] !== "/")  // cd dir
		dir.push(line[2])
    else if (!(line[0] === "$") && line[0] !== "dir") { 
        let size = parseInt(line[0])
        let aux = Array.from(dir)
        while(aux.length > 0) {
            let key = aux.join("/")
            if( !(key in folder_sizes)) {
                folder_sizes[key] = 0
            }
            folder_sizes[key] += size
			aux.pop()
        }
    }
}

let star1 = 0
i = -1 
let values = Object.values(folder_sizes)
while (++i < Object.keys(folder_sizes).length) {
	if (values[i] <= 100000) 
		star1 += values[i]
}

let spaceNeeded =  values[0] + 30000000 - 70000000
let star2 = values[0]
i = -1 
while (++i < Object.keys(folder_sizes).length) {
	if (values[i] >= spaceNeeded && values[i] < star2) 
		star2 = values[i]
}
console.log("First ⭐️: "+ star1)
console.log("Second ⭐️: " + star2)