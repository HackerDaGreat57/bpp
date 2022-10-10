//main.js: Blender++ Live main source code
const reactElement = React.createElement;

class AppTitle extends React.Component {
  render() {
    return React.createElement("div", ' ', React.createElement("span", {
      style: {
        fontWeight: 'bold'
      }
    }, null, "Blender++ Live"));
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(AppTitle));

export default function App() {
  return /*#__PURE__*/React.createElement("div", null, "Coding", ' ', /*#__PURE__*/React.createElement("span", {
    style: {
      fontWeight: 'bold'
    }
  }, "Beauty"));
}