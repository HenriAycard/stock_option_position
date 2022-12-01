# Portfolio

Portfolio is a Python library for modeling your active stock portfolio. This library calculate the ‘Active’ Portfolio holdings and adjusted per holding costs based on the start date provided.

## Installation

Use the package manager python to install Portfolio. 

```bash
python3 setup.py install
```

## Usage

```python
>>> import Portfolio as ptf
>>> import datetime

# Initialise some positions
>>> your_pos = ptf.Position(1158, datetime.date(2019, 2, 8), datetime.date(2019, 2, 8), "BUY", 195.972, 14, 0, 13.998)
>>> another_pos = ptf.Position(1158, datetime.date(2019, 9, 14), datetime.date(2019, 9, 14), "SELL.FIFO", 40.56, 4, 0, 10.14)

# Add your positions
>>> positions_data = ptf.Positions()
>>> positions_data.add_position(your_pos)
>>> positions_data.add_position(another_pos)

# Initialise an portfolio with a start date
>>> your_portfolio = ptf.Portfolio(datetime.datetime.now())

# Add your positions to your portfolio
>>> your_portfolio.set_position(positions_data)

>>> print(your_portfolio)
Date:Thu Dec  1 21:37:48 2022

Position:
[1158, Friday, February 08 2019, Friday, February 08 2019, BUY, 195.972000, 14.000000, 0.000000, 13.998000]
[1158, Saturday, September 14 2019, Saturday, September 14 2019, SELL.FIFO, 40.560001, 4.000000, 0.000000, 10.140000]
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)