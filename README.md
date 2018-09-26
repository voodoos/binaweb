# binaweb

https://voodoos.github.io/binaweb

## Run Project

```sh
$ yarn
$ yarn start
```

After you see the Parcel compilation succeed (the `Built in ***s` message), open up `http://localhost:1234`.


## Build for Production

```sh
yarn build
```

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
