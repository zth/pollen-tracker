## pollen-tracker

[View the application](https://pollen-tracker.now.sh/)

## Setting the project up locally

First of all make sure you are using node `12.13.1` (any node 12.x would also do) and latest yarn, you can always have a look at the `engines` section of the `package.json`.

Copy `dev.env.build` to `.env.build` and enter missing details.
These can be found in 1Password as `PWA Secrets`.

```sh
$ yarn (install)
$ yarn dev
```

After doing this, you'll have a server with hot-reloading running at [http://localhost:3000](http://localhost:3000) and a graphql server running at [http://localhost:3000/api/graphql](http://localhost:3000/api/graphql).

## When changing the graphql server schema

```sh
$ yarn dev
$ yarn update-graphql
```

## Run Checks

```sh
$ yarn format
$ yarn typecheck
$ yarn lint
```

or

```sh
$ yarn checks
```

## Useful Now.sh commands

```sh

# force a deploy
$ yarn now

# check all running instances
$ yarn now ls

# check logs for a given instance
$ yarn now logs pollen-tracker.now.sh --all
```
