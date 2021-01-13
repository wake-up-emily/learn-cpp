class Sales_data():
    def __init__(self,isbn,units_sold,sale_price,selling_price):
        self.isbn = isbn
        self.units_sold = units_sold
        self.sale_price = sale_price
        self.selling_price = selling_price

        self.revenue = self.selling_price * self.units_sold
        self.get_discount()

    def get_discount(self):
        if self.sale_price != 0:
            self.discount = self.selling_price / self.sale_price
        else:
            self.discount = 0

    def __eq__(self, other):
        if self.isbn == other.isbn and \
            type(self) == type(other):
            return True
        else:
            return False

    def __hash__(self):
        return hash(self.isbn)

    def compare_isbn(self,other):
        if self == other:
            return True
        else:
            return False

    def __iadd__(self, other):
        if isinstance(other, Sales_data):
            self.units_sold += other.units_sold
            self.revenue += other.revenue
            self.selling_price = self.revenue / self.units_sold
            self.discount = self.selling_price / self.sale_price
            return self
        else:
            return NotImplemented

    def __add__(self,other):
        if isinstance(other, Sales_data):
            import copy
            new_data = copy.deepcopy(self) #不同内存地址 && 不同数据
            new_data += other
            return new_data

    def __repr__(self):
        return "{0} {1} {2} {3} {4} {5}".format(self.isbn, self.units_sold, round(self.selling_price,2), self.revenue, self.sale_price ,round(self.discount,2))


data1 = Sales_data('x86-12345',2,100,80)
print(data1)
data2 = Sales_data('x86-12345',3,100,70)
print(data2)
print(data1 == data2)
print(data1.compare_isbn(data2))
print(data1)
print(data1 + data2)
print(data1)
data1 += data2
print(data1)

"""
x86-12345 2 80 160 100 0.8
x86-12345 3 70 210 100 0.7
True
True
x86-12345 2 80 160 100 0.8
x86-12345 5 74.0 370 100 0.74
x86-12345 2 80 160 100 0.8
x86-12345 5 74.0 370 100 0.74
"""