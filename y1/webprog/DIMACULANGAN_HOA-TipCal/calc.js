const inputBill = document.getElementById('bill');
const inputTip = document.getElementById('tip');
const dispTotal = document.getElementById('total');

calc = () => {
    let tip = Number(inputTip.value) / 100;
    let bill = Number(inputBill.value);
    
//    let inputValid = !((tip == NaN) || (bill == NaN));
    let inputValid = !(isNaN(tip) || isNaN(bill));
    inputValid = inputValid && !(tip == 0 || bill == 0);

    console.log(`bill = ${bill}\ntip = ${tip}\ninputValid = ${inputValid}`);

    if (inputValid) {
        dispTotal.innerHTML = bill + (tip * bill);
    } else {
        dispTotal.innerHTML = "Input both numbers, please~";
    }
}
