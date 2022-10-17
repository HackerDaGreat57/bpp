//main.js: Blender++ Live main source code

//Create the screen, basically
const reactElement = React.createElement;

//Styles
const appTitle_style = {
  fontFamily: 'Tahoma',
  fontSize: '2em',
  fontWeight: 'bold',
  color: 'black'
};

const app_bg = {
  backgroundColor: '#454545',
  width: '100%',
  height: '100%'
}

function App() {
  return React.createElement("div", null, React.createElement("span", {
    style: app_bg
  }, null));
}

class AppTitle extends React.Component {
  render() {
    return React.createElement("div", null, React.createElement("span", {
      style: appTitle_style
    }, null, "Blender++ Live"));
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(AppTitle));