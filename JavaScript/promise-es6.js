'use strict';

var isMomHappy = true;

var willGetNewPhone = new Promise(
	(resolve, reject) => {
		if (isMomHappy) {
			const phone = {
				brand: 'Apple',
				color: 'black',
			};
			resolve(phone);
		} else {
			const reason = new Error('mom is not happy');
			reject(reason);
		}
	}
);

var askMom = function () {
	willGetNewPhone
		.then(
			phone => Promise.resolve(
				'I get a new ' + phone.color + ' ' + phone.brand + ' phone'
			)
		)
		.then(fulfilled => console.log(fulfilled))
		.catch(error => console.log(error.message));
};

askMom();