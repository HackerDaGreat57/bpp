//main.js: Blender++ Live main source code
const reactElement = React.createElement;

class AppTitle extends React.Component {
  render() {
    return React.createElement("div", null, React.createElement("span", {
      className: "apptitle"
    }, null, "Blender++ Live"));
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(AppTitle));

export default function App() {
  return React.createElement("div", null, "Coding ", React.createElement("span", {className: "bold"}, "Beauty"));
}