/* Dimaculangan, Gionne Niño P.
 * 2026 Jan 16
 * JavaScript remains a monstrous mess of spaghetti
 *
 * pov: C/C++/Rust developer programs in JS
 *
 * there are many comments because i share these to my classmates on GitHub:
 * https://github.com/OninDynamics/school
 *
 * NO AI IS USED, only schezophrenic amounts of searching the MDN docs:
 * https://developer.mozilla.org/
 */

// The whole loading screen thing
(() => {

	const loadingTimeInSecs = 2; // configure this if wanna
	const loadingScreen = document.getElementById("loadingscreen");

	setTimeout(() => {
		loadingScreen.className += " fadeout";
		setTimeout(() => {
			loadingScreen.remove();
		}, 500);
	}, loadingTimeInSecs * 1000);

})();

// The actual form handling thing, put into an object for later reuse c;
// Email regexp pattern based on RFC 2822 Email Validation with slight
// optimizations from me (onind) :) OG source: https://regexr.com/2rhq7
const registerForm = {
	// declare regexprs only once, doing it in a function could incur
	// performance costs due to regex compilation
	emailPattern: /\b[\w!#$%&'*+/=?^`{|}~-]+(?:\.[\w!#$%&'*+/=?^`{|}~\-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\b/,

	passwordPattern: /.{8}/, // password must have at least 8 of any characters

	textFields: {
		fname: document.forms["registerForm"].elements["fname"],
		lname: document.forms["registerForm"].elements["lname"],
		email: document.forms["registerForm"].elements["email"],
		password: document.forms["registerForm"].elements["password"],
		confirmPW: document.forms["registerForm"].elements["confirmPW"],
	},

	submitButton: document.forms["registerForm"].elements["registerButton"],

	emailValid: function() {
		return this.emailPattern.test(this.textFields.email.value);
	},

	isFilled: function() {
		return !(Object.values(this.textFields).values().some((field) => {return field.value == ""}));
	},

	samePassword: function() {
		return this.textFields.password.value == this.textFields.confirmPW.value;
	},

	passwordValid: function() {
		return this.passwordPattern.test(this.textFields.password.value);
	},
};

// only way i could get this thing to work without messing with the weird rules
// around the scope of the "this" keyword, at least without AI
document.forms["registerForm"].addEventListener("input", function() {
	if (!registerForm.isFilled()) {
		registerForm.submitButton.disabled = true;
		registerForm.submitButton.value = "Please fill out all fields...";
		return;
	} if (!registerForm.emailValid()) {
		registerForm.submitButton.disabled = true;
		registerForm.submitButton.value = "Your email address isn't valid...";
		return;
	} if (!registerForm.passwordValid()) {
		registerForm.submitButton.disabled = true;
		registerForm.submitButton.value = "You password is too short...";
		return;
	} if (!registerForm.samePassword()) {
		registerForm.submitButton.disabled = true;
		registerForm.submitButton.value = "Your passwords aren't the same...";
		return;
	} else {
		registerForm.submitButton.disabled = false;
		registerForm.submitButton.value = "Register Now!";
		return;
	}
});

// the initialization step, we're finished now
registerForm.submitButton.disabled = true;
registerForm.submitButton.value = "Please fill out all fields...";
