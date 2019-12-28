import Document, { Head, Main, NextScript } from 'next/document';
import React from 'react';

const serviceWorkerRegistration = `
  document.addEventListener('DOMContentLoaded', event => {
    if ('serviceWorker' in navigator) {
      window.addEventListener('load', () => {
        navigator.serviceWorker.register('/service-worker.js', { scope: "/" }).then(registration => {
          console.log('SW registered: ', registration)
        }).catch(registrationError => {
          console.log('SW registration failed: ', registrationError)
        })
      })
    }
  })
`;

export default class MyDocument extends Document {
  render() {
    return (
      <html lang="en">
        <Head>
          <meta name="apple-mobile-web-app-title" content="Pollen Tracker" />
          <meta
            name="apple-mobile-web-app-status-bar-style"
            content="default"
          />
          <meta
            name="viewport"
            content="width=device-width, initial-scale=1, shrink-to-fit=no"
          />
          <meta name="name" content="pollen-tracker" />
          <meta
            name="description"
            content="pollen tracker allergies melbourne australia"
          />
          <meta name="mobile-web-app-capable" content="yes" />
          <meta name="apple-mobile-web-app-capable" content="yes" />
          <meta name="theme-color" content="#FFFFFF" />

          {process.env.isProd && (
            <>
              <link
                rel="apple-touch-icon"
                sizes="180x180"
                href="/static/apple-touch-icon.png"
              />
              <link
                rel="icon"
                type="image/png"
                sizes="32x32"
                href="/static/favicon-32x32.png"
              />
              <link
                rel="icon"
                type="image/png"
                sizes="16x16"
                href="/static/favicon-16x16.png"
              />
              <link
                href="/static/splashscreens/iphone5_splash.png"
                media="(device-width: 320px) and (device-height: 568px) and (-webkit-device-pixel-ratio: 2)"
                rel="apple-touch-startup-image"
              />
              <link
                href="/static/splashscreens/iphone6_splash.png"
                media="(device-width: 375px) and (device-height: 667px) and (-webkit-device-pixel-ratio: 2)"
                rel="apple-touch-startup-image"
              />
              <link
                href="/static/splashscreens/iphoneplus_splash.png"
                media="(device-width: 621px) and (device-height: 1104px) and (-webkit-device-pixel-ratio: 3)"
                rel="apple-touch-startup-image"
              />
              <link
                href="/static/splashscreens/iphonex_splash.png"
                media="(device-width: 375px) and (device-height: 812px) and (-webkit-device-pixel-ratio: 3)"
                rel="apple-touch-startup-image"
              />
              <link
                href="/static/splashscreens/ipad_splash.png"
                media="(device-width: 768px) and (device-height: 1024px) and (-webkit-device-pixel-ratio: 2)"
                rel="apple-touch-startup-image"
              />
              <link
                href="/static/splashscreens/ipadpro1_splash.png"
                media="(device-width: 834px) and (device-height: 1112px) and (-webkit-device-pixel-ratio: 2)"
                rel="apple-touch-startup-image"
              />
              <link
                href="/static/splashscreens/ipadpro2_splash.png"
                media="(device-width: 1024px) and (device-height: 1366px) and (-webkit-device-pixel-ratio: 2)"
                rel="apple-touch-startup-image"
              />
              <link rel="manifest" href="/static/manifest.json" />
            </>
          )}
        </Head>
        <body>
          <main>
            <Main />
          </main>
          <NextScript />
          {process.env.isProd && (
            <script
              type="text/javascript"
              dangerouslySetInnerHTML={{ __html: serviceWorkerRegistration }}
            />
          )}
        </body>
      </html>
    );
  }
}
