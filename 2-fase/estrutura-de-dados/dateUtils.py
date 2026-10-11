from datetime import date, datetime, timedelta


class DateUtils:
    @staticmethod
    def pascoa_day(year: int | str) -> str:
        """
        Calcula o domingo de Páscoa (algoritmo de Gauss para 1900-2099).
        Source: https://pt.wikipedia.org/wiki/Cálculo_da_Páscoa
        https://www.inf.ufrgs.br/~cabral/Pascoa.html
        """
        X = 24
        Y = 5
        ano = int(year)
        a = ano % 19
        b = ano % 4
        c = ano % 7
        d = ((19 * a) + X) % 30
        e = ((2 * b) + (4 * c) + (6 * d) + Y) % 7

        if (d + e) < 10:
            dia = d + e + 22
            mes = 3
        else:
            dia = d + e - 9
            mes = 4

        return date(ano, mes, dia).isoformat()

    def is_holidays_brazil(self, iso_date: str) -> bool:
        """Verifica se a data fornecida é um feriado nacional no Brasil."""
        date_base = iso_date.split("T")[0]
        dt = datetime.fromisoformat(date_base).date()
        year = dt.year

        pascoa = self.pascoa_day(year)
        holy_friday = self.add_days_to_date(pascoa, -2)
        carnaval = self.add_days_to_date(pascoa, -47)
        corpus_christi = self.add_days_to_date(pascoa, 60)
        pentecost = self.add_days_to_date(pascoa, 50)

        holidays = {
            pascoa,
            holy_friday,
            carnaval,
            corpus_christi,
            pentecost,
            f"{year}-01-01",
            f"{year}-04-21",
            f"{year}-05-01",
            f"{year}-09-07",
            f"{year}-10-12",
            f"{year}-11-02",
            f"{year}-11-15",
            f"{year}-12-25",
            f"{year}-12-31",
        }

        return date_base in holidays

    def is_working_day(self, iso_date: str) -> bool:
        """Verifica se a data é um dia útil (segunda a sexta e não feriado)."""
        if self.is_holidays_brazil(iso_date):
            return False

        dt = datetime.fromisoformat(iso_date.split("T")[0]).date()
        # Em Python: Monday é 0 e Sunday é 6
        return dt.weekday() < 5


date_utils = DateUtils()