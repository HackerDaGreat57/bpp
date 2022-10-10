//main.js: Blender++ Live main source code
const reactElement = React.createElement;

class AppTitle extends React.Component {
  render() {
    return React.createElement("div", null, "Blender++ Live", React.createElement("span", {
      style: {
        fontWeight: 'bold'
      }
    }));
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(AppTitle));