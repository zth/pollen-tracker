module.exports = api => {
  api.cache(true);

  return {
    presets: ['next/babel'],
    plugins: [
      '@babel/plugin-proposal-optional-chaining',
      '@babel/proposal-class-properties',
      '@babel/proposal-object-rest-spread',
      'relay',
    ],
  };
};
