// woa, arrowfunction syntax

let counter = document.getElementById("counter");
let count = Number(counter.innerHTML);

inv = (num) => {
    if (num == undefined) {
        count = 1;
    } else {
        count += num;
    }

    counter.innerHTML = count;
}
