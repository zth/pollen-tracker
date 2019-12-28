const purgecss = require('@fullhuman/postcss-purgecss')({
  content: ['./src/**/*.tsx'],
  defaultExtractor: content => content.match(/[A-Za-z0-9-_:/]+/g) || [],
});

module.exports = {
  plugins: [
    require('postcss-easy-import'),
    require('tailwindcss'),
    ...(process.env.NODE_ENV === 'production' ? [purgecss] : []),
    require('autoprefixer'),
    require('cssnano'),
  ],
};
