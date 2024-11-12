let counter = document.getElementById("counter");
let count = Number(counter.innerHTML);

// it's just a function that increments/decrements the counter
inv = (num) => {
    if (num == undefined) {
        count = 1;
    } else if ((count + num) >= 0) {
        count += num;
    }

    counter.innerHTML = count;
}
