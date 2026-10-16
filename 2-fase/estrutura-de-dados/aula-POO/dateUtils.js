'use strict'

class DateUtils {
	pascoaDay(year) {
		/* source https://pt.wikipedia.org/wiki/Cálculo_da_Páscoa || https://www.inf.ufrgs.br/~cabral/Pascoa.html
		* Faixa de anos | X  | Y
		*  1990 - 2099	| 24 | 5
		*  2100 - 2199  | 24 | 6
		*  2200 - 2299  | 25 | 7
		*/
		const X = 24
		const Y = 5
		let dia
		let mes
		const ano = Number(year)
		const a = (ano % 19)
		const b = (ano % 4)
		const c = (ano % 7)
		const d = ((19 * a) + X) % 30
		const e = ((2 * b) + (4 * c) + (6 * d) + Y) % 7

		if ((d + e) < 10) { dia = (d + e + 22); mes = 3 }
		else { dia = (d + e - 9); mes = 4 }
		return new Date(`${ano}-${mes}-${dia}`).toISOString().split('T')[0]
	}

	isHolidaysBrazil(isoDate) {
		const dateBase = isoDate.split('T')[0]
		const year = new Date(isoDate).getFullYear()
		const pascoa = this.pascoaDay(year)
		const holyFriday = this.addDaysToDate(pascoa, -2)
		const carnaval = this.addDaysToDate(pascoa, -47)
		const corpusChristi = this.addDaysToDate(pascoa, 60)
		const pentecost = this.addDaysToDate(pascoa, 50)

		const holidays = [
			pascoa,
			holyFriday,
			carnaval,
			corpusChristi,
			pentecost,
			`${year}-01-01`,
			`${year}-04-21`,
			`${year}-05-01`,
			`${year}-09-07`,
			`${year}-10-12`,
			`${year}-11-02`,
			`${year}-11-15`,
			`${year}-12-25`,
			`${year}-12-31`,
		]

		return holidays.includes(dateBase)
	}

	addDaysToDate(isoDate, daysToAdd) {
		const inputDate = isoDate ? new Date(isoDate) : new Date()
		const millisecondsPerDay = 24 * 60 * 60 * 1000;
		const addedMilliseconds = daysToAdd * millisecondsPerDay;

		const resultDate = new Date(inputDate.getTime() + addedMilliseconds);
		return resultDate.toISOString().split('T')[0]
	}


	isWorkingDay(isoDate) {
		const holliday = this.isHolidaysBrazil(isoDate)
		const weekday = new Date(isoDate).getDay()
		if (!holliday) {
			if (weekday > 0 && weekday < 6) return true
		}
		return false
	}

	nextWorkingDay(isoDate) {
		const nextDay = this.addDaysToDate(isoDate, 1)
		const workingDay = this.isWorkingDay(nextDay)
		if (!workingDay) return this.nextWorkingDay(nextDay)
		else return nextDay
	}

	differenceDate(isoDateStart, isoDateEnd) {
		const start = isoDateStart ?  new Date(isoDateStart) : new Date();
		const end = isoDateEnd ? new Date(isoDateEnd) : new Date();
		
		const dif = (end - start);
		const days = dif / (1000 * 60 * 60 * 24);
		
		return {
			dif: dif,
			days: days,
			text: days >= 1 ? 'more than 1 day' : 'less than 1 day',
		};
	}
}
module.exports = new DateUtils
