//main.js: Blender++ Live main source code
const reactElement = React.createElement;

class AppTitle extends React.Component {
  render() {
    return React.createElement("div", ' ', React.createElement("span", {
      style: {
        fontWeight: 'bold',
        "apptitle"
      }
    }, null, "Blender++ Live"));
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(AppTitle));