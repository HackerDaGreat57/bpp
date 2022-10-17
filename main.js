//main.js: Blender++ Live main source code

//Create the screen, basically
const reactElement = React.createElement;

function App() {
  return React.createElement("div", {
    style: {
      backgroundColor: '#454545',
      width: '100%',
      height: '100%'
    }
  });
}

class AppTitle extends React.Component {
  render() {
    return React.createElement("div", null, React.createElement("span", {
      style: {
        fontFamily: 'Tahoma',
        fontSize: '2em',
        fontWeight: 'bold',
        color: 'black'
      }
    }, null, "Blender++ Live"));
  }
}

const domContainer = document.querySelector('#render_area');
const root = ReactDOM.createRoot(domContainer);
root.render(reactElement(AppTitle));
export default App;