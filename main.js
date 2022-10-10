//main.js: Blender++ Live main source code
const css = require('main.css');

const reactElement = React.createElement;

class AppTitle extends React.Component {
  render() {
    return React.createElement("div", ' ', React.createElement("span", {
      style: {
        FontFace: "bpp_Tahoma",
        fontWeight: 'bold'
      }
    }, null, "Blender++ Live"));
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(AppTitle));