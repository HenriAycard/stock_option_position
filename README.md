# Portfolio

Portfolio is a Python library for modeling your active stock portfolio. This library calculate the ‘Active’ Portfolio holdings and adjusted per holding costs based on the start date provided.

## Installation

Use the package manager python to install Portfolio. 

```bash
python3 setup.py install
```

## Usage

```python
import Portfolio as ptf
import datetime

# Initialise some positions
your_pos = ptf.Position(1,1,1158,2,1,195.972,20190208,20190208,14,0,13.998)
another_pos = ptf.Position(2,1,1687,2,3,507.9205,20201028,20201028,145,0,3.5029)

# Add your positions
positions_data = ptf.Positions()
positions_data.add_position(your_pos)
positions_data.add_position(another_pos)

# Initialise an portfolio with a start date
your_portfolio = ptf.Portfolio(datetime.datetime.now())

# Add your positions to your portfolio
your_portfolio.set_position(positions_data)
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)