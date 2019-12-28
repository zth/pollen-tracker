const { colors } = require('tailwindcss/defaultTheme');

module.exports = {
  theme: {
    extend: {
      colors: {
        green: {
          ...colors.green,
          domain: '#54aa3c',
        },
      },
    },
  },
  variants: {},
  plugins: [],
};
