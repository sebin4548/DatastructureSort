import {useState, useEffect} from "react"

function App(){
  const [loading, setLoading] = useState(true);
  const [movies, setMovies] = useState([]);
  useEffect( () => {
    fetch(`https://yts.mx/api/v2/list_movies.json?minimum_rating=8.8&sort_by=year`
    ).then(response => response.json()
    ).then(json => {
      setMovies(json.data.movies);
      setLoading(false);
    })
  }, []);
  
  return(<div>
    {loading ? <h1>loading </h1> : movies.map(
      movie =>(
      <div key={movie.id}>
        <h3>{movie.title}</h3>
        <img src={movie.large_cover_image}/>
      </div>) ) }
    
  </div>)
}
export default App;

